<?php
/**
 * @file
 *
 */

$plugin = [
  'title' => t("Player of the week"),
  'description' => t('Give me a team and I will pick a player of the week'),
  'category' => t('Custom'),
  'required context' => new ctools_context_required(t("Team Node"), 'node'),
];

/**
 * Output function
 */
function sand_camp_demo_player_of_the_week_content_type_render($subtype, $conf, $panel_args, $context) {
  $team = $context->data;
  if (empty($team) || $team->type != 'team') return;

  $wrapper = entity_metadata_wrapper('node', $team);
  $block = new stdClass();
  $block->content = [
    '#prefix' => "<h2>Player of the week</h2>",
    '#markup' => $wrapper->field_players[rand(0,9)]->title->value()
  ];
  return $block;
}

function sand_camp_demo_player_of_the_week_content_type_edit_form($form, &$form_state) {
  /** Defined so that context has a place to be set. */
  return $form;
}