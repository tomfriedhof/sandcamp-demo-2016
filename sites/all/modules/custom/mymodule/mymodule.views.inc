<?php

/**
 * Implements hook_views_data().
 */
function mymodule_views_data() {
  return [
    'views' => [
      'mymodule_area' => [
        'title' => t('My Custom Area'),
        'help' => t('Makes a cool api request or something'),
        'area' => [
          'handler' => 'Drupal\mymodule\Views\Handlers\Area\MyCoolHandler'
        ]
      ]
    ],
    'node' => [
      'my_custom_field' => [
        'title' => t('My Custom Field'),
        'help' => t('Showing how to write fields at SandCamp'),
        'real field' => 'created',
        'field' => [
          'handler' => 'Drupal\mymodule\Views\Handlers\Field\MyCustomField'
        ],
        'filter' => [
          'handler' => 'Drupal\mymodule\Views\Handlers\Filter\MyCustomFilter'
        ]

      ],
    ]
  ];
}