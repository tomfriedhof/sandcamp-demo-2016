<?php

namespace Drupal\mymodule\Views\Handlers\Area;

class MyCoolHandler extends \views_handler_area {
  function option_definition() {
    $options = parent::option_definition();

    $options['something'] = array('default' => '');

    return $options;
  }


  function options_form(&$form, &$form_state) {
    $form['something'] = [
      '#type' => 'textfield',
      '#title' => t('Some text field'),
      '#default_value' => isset($this->options['something']) ? $this->options['something'] : '',
    ];
    parent::options_form($form, $form_state);
  }

}