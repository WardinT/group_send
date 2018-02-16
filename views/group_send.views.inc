<?php

/**
 * Implements hook_views_data_alter().
 */
function group_send_views_data_alter(&$data) {
  $data['views']['group_send'] = array(
    'title' => t('Send group mail'),
    'help' => t('Provide a checkbox to select the row designating a group for e-mail sending.'),
    'field' => array(
      'handler' => 'group_send_handler_field_selector',
      'click sortable' => FALSE,
    ),
  );
}
