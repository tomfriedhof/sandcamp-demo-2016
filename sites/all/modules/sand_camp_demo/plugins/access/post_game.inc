<?php

$plugin = array(
  'title' => t("Post Game"),
  'description' => t('Is game in the past.'),
  'callback' => 'sand_camp_demo_page_access_check',
  'summary' => 'sand_camp_demo_page_access_summary',
  'required context' => new ctools_context_required(t('Game Node'), 'node'),
);

/**
 * Check for access.
 */
function sand_camp_demo_page_access_check($conf, $context) {
  $game = $context->data;
  return $game->field_game_time[LANGUAGE_NONE][0]['value'] < date('Y-m-d 00:00:00');
}

/**
 * Provide a summary description based upon the checked roles.
 */
function sand_camp_demo_page_access_summary($conf, $context) {
  return t('Check to see if came occurs in the past');
}

