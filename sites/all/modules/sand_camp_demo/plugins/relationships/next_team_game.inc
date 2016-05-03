<?php

/**
 * @file
 * Plugin to provide an relationship handler for node from user.
 */

/**
 * Plugins are described by creating a $plugin array which will be used
 * by the system that includes this file.
 */
$plugin = array(
  'title' => t('Next Game Team Plays'),
  'keyword' => 'game',
  'description' => t('Loads the next game the team plays.'),
  'required context' => new ctools_context_required(t('Team node'), 'node'),
  'context' => 'sand_camp_game_from_team_context',
);

/**
 * Return a new context based on an existing context.
 */
function sand_camp_game_from_team_context($context, $conf) {
  // If unset it wants a generic, unfilled context, which is just NULL.
  if (empty($context->data) || !isset($context->data->nid) || $context->data->type == 'game') {
    return ctools_context_create_empty('node', NULL);
  }

  if (isset($context->data->nid)) {
    $q = new EntityFieldQuery();
    $q->entityCondition('entity_type', 'node')
      ->entityCondition('bundle', 'game')
      ->propertyCondition('status', 1)
      ->fieldCondition('field_competing_teams', 'target_id', $context->data->nid, '=')
      ->fieldCondition('field_game_time', 'value', date('Y-m-d 00:00:00'), '>=')
      ->fieldOrderBy('field_game_time', 'value', 'ASC');
    $results = $q->execute();

    if (empty($results)) return ctools_context_create_empty('node', NULL);

    $nodes = node_load_multiple(array_keys($results['node']));
    return ctools_context_create('node', reset($nodes));
  }
}
