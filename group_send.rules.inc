<?php

/**
* Implementation of hook_rules_event_info().
*/
function group_send_rules_event_info() {
  $defaults = array(
    'group' => t('Group Send'),
  );
  return array(
    'group_send_email_sent' => $defaults + array(
      'label' => t('After sending an individual email'),
      'variables' => array(
        'group_send_email_message' => array(
          'type' => 'group_send_email_message',
          'label' => t('e-mail message'),
          'description' => t('All information about the message.')
        ),
      ),
    ),
    'group_send_all_email_added_to_spool' => $defaults + array(
      'label' => t('After adding all e-mails to the spool'),
      'variables' => array(
        'group_send_email_count' => array(
          'type' => 'integer',
          'label' => t('message count'),
          'description' => t('The number of messages added to the spool.')
        ),
      ),
    ),
    'group_send_email_added_to_spool' => $defaults + array(
      'label' => t('After adding an individual e-mail to the spool'),
      'variables' => array(
        'group_send_email_message' => array(
          'type' => 'group_send_email_message',
          'label' => t('e-mail message'),
          'description' => t('All information about the message.')
        ),
      ),
    ),
  );
}

/**
* Implementation of hook_rules_data_info().
*/
function group_send_rules_data_info() {
  return array(
    'group_send_email_message' => array(
      'label' => t('Group Send e-mail message'), 
      'group' => t('Group Send'), 
      'wrap' => TRUE, 
      'property info' => _group_send_email_message_property_info(),
    ),
  );
}
