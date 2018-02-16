(function ($) {
  // Polyfill for jQuery less than 1.6.
  if (typeof $.fn.prop != 'function') {
    jQuery.fn.extend({
      prop: jQuery.fn.attr
    });
  }

  Drupal.behaviors.groupSend = {
    attach: function(context) {
      $('.group-send-selection-form', context).each(function() {
        Drupal.groupSend.initTableBehaviors(this);
        Drupal.groupSend.initGenericBehaviors(this);
      });
    }
  }

  Drupal.groupSend = Drupal.groupSend || {};
  Drupal.groupSend.initTableBehaviors = function(form) {
    $('.group-send-table-select-all', form).show();
    // This is the "select all" checkbox in (each) table header.
    $('.group-send-table-select-all', form).click(function() {
      var table = $(this).closest('table')[0];
      $('input[id^="edit-group-send"]:not(:disabled)', table).prop('checked', this.checked).change();
    });
  }

  Drupal.groupSend.initGenericBehaviors = function(form) {
    // Show the "select all" fieldset.
    $('.group-send-select-all-markup', form).show();

    $('.group-send-select-this-page', form).click(function() {
      $('input[id^="edit-group-send"]', form).prop('checked', this.checked).change();

      // Toggle the "select all" checkbox in grouped tables (if any).
      $('.group-send-table-select-all', form).prop('checked', this.checked).change();
    });

    $('.group-send-select', form).click(function() {
      // If a checkbox was deselected, uncheck any "select all" checkboxes.
      if (!this.checked) {
        $('.group-send-select-this-page', form).prop('checked', false).change();

        var table = $(this).closest('table')[0];
        if (table) {
          // Uncheck the "select all" checkbox in the table header.
          $('.group-send-table-select-all', table).prop('checked', false).change();
        }
      }
    });
  }

})(jQuery);
