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
  'title' => t('Team player is on'),
  'keyword' => 'team',
  'description' => t('Loads the team that given player is on.'),
  'required context' => new ctools_context_required(t('Player node'), 'node'),
  'context' => 'sand_camp_team_from_player_context',
);

/**
 * Return a new context based on an existing context.
 */
function sand_camp_team_from_player_context($context, $conf) {
  // If unset it wants a generic, unfilled context, which is just NULL.
  if (empty($context->data) || !isset($context->data->nid)) {
    return ctools_context_create_empty('node', NULL);
  }

  if (isset($context->data->nid)) {
    $q = new EntityFieldQuery();
    $q->entityCondition('entity_type', 'node')
      ->entityCondition('bundle', 'team')
      ->propertyCondition('status', 1)
      ->fieldCondition('field_players', 'target_id', $context->data->nid, '=');
    $results = $q->execute();

    if (empty($results)) return ctools_context_create_empty('node', NULL);

    $nodes = node_load_multiple(array_keys($results['node']));
    return ctools_context_create('node', reset($nodes));
  }
}
