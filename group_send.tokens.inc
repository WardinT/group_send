<?php

/**
 * @file
 * Token integration for the Group Send module.
 */

/**
 * Implements hook_token_info().
 *
 * These token are used by Rules and not in the Views form.
 */
function group_send_token_info() {
  $data = array();
  foreach (_group_send_email_message_property_info() as $key => $info) {
    $data[$key] = array(
      'name' => $info['label'],
      'description' => ''
    );
  }
  $type = array(
    'name' => t('Group Send e-mail message'),
    'description' => t('Tokens for Group Send e-mail message.'),
    'needs-data' => 'group_send_email_message',
  );
  return array(
    'types' => array('group_send_email_message' => $type),
    'tokens' => array('group_send_email_message' => $data),
  );
}

/**
 * Implementation hook_tokens().
 *
 * These token replacements are used by Rules and not in the Views form.
 */
function group_send_tokens($type, $tokens, array $data = array(), array $options = array()) {
  $replacements = array();
  if ($type == 'group_send_email_message' && !empty($data['group_send_email_message'])) {
    foreach ($tokens as $name => $original) {
      $replacements[$original] = $data['group_send_email_message']->{$name};
    }
  }
  return $replacements;
}
