<?php
/**
 * Created by PhpStorm.
 * User: tomfriedhof
 * Date: 2/22/16
 * Time: 3:15 PM
 */

namespace Drupal\mymodule\Views\Handlers\Filter;


class MyCustomFilter extends \views_handler_filter {
  function option_definition() {
    $options = parent::option_definition();

    $options['even_odd'] = array('default' => 'odd');

    return $options;
  }

  function options_form(&$form, &$form_state) {
    $form['even_odd'] = [
      '#type' => 'radios',
      '#title' => t('Even or Odd'),
      '#default_value' => $this->options['even_odd'],
      '#options' => ['odd' => t('Only odd numbers'), 'even' => t('Just even numbers')],
      '#description' => t('Demonstrating how to create your own options form')
    ];

    parent::options_form($form, $form_state);
  }

  function admin_summary() {
    return $this->options['even_odd'] == 'even' ? t('Just even numbers') : t('Just odd numbers');
  }

  function query() {
    $this->ensure_my_table();
    $operator = $this->options['even_odd'] == 'even' ? '=' : '>';
    $this->query->add_where_expression($this->options['group'], "($this->table_alias.$this->real_field % 2) $operator 0");
  }

}