<?php
/**
 * @file
 * sand_camp_demo.features.inc
 */

/**
 * Implements hook_node_info().
 */
function sand_camp_demo_node_info() {
  $items = array(
    'division' => array(
      'name' => t('Division'),
      'base' => 'node_content',
      'description' => t('The group of teams that play each other'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'game' => array(
      'name' => t('Game'),
      'base' => 'node_content',
      'description' => t('A game between two teams.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'player' => array(
      'name' => t('Player'),
      'base' => 'node_content',
      'description' => t('A player that plays for a team'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'team' => array(
      'name' => t('Team'),
      'base' => 'node_content',
      'description' => t('A team that plays in the league.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
