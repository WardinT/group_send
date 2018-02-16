
Group Send allow mass mailing to taxonomy-based groups using Views.
The messages are queued in a spool table and delivered only on cron.
You can control how many messages will be send per cron run.

CONFIGURATION

General settings can be configured at: Site Configuration > Group Send

USAGE

 1. Create a view and add at least one column containing term references designating the group.
    Group members and their mail addresses will be retrieved from the database.
 2. [Optional] Expose Views filters to let the user easily build list of
    recipients using UI.
 3. Add the "Global: Send  group mail" field to your view. This field provides the checkboxes
    that allow the user to select multiple rows.
 4. Save the view, load the page, use exposed filters to build the list, select
    all or some rows and choose "Send group mail".
 5. Fill the message form to configure the e-mail. Use tokens to personalize
    your e-mail.
 6. Preview and send the message.

DEPENDENCIES & INTEGRATION

 * Group Send relies on groups being defined as (hierarchical) taxonomies with users assigned.
 * Group Send depends on Views.
 * The module integrates features from:
  o Mime Mail. When the Mime Mail module is enabled, the user can choose to send
    rich HTML messages and/or use attachments.
  o Tokens. When the Tokens module is enabled, the user can insert context tokens
    into the subject or body of the message. Note that row-based tokens are
    available even if Tokens module is disabled.
  o Rules. When the Rules module is enabled, the user can define actions 
    for when emails are sent and/or placed in the spool.

FOR DEVELOPERS / HOOKS

The module provides two hooks: 
 * hook_group_send_mail_queued($message, $view, $row_id)
   Called just after each message is queued. 
 * hook_group_send_mail_alter(&$message)
   Called just before each message is queued.

MAINTAINERS & SPONSORS

 * Based on the Views send module by Hans Fredrik Nordhaug (hansfn) | http://drupal.org/user/40521
 * Module author Thomas Wardin | https://www.drupal.org/user/2302178
