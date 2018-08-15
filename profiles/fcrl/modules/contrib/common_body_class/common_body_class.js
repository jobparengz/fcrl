/**
 * @file
 * Provide the summary information for the common body class settings vertical tabs.
 */

(function ($) {
  'use strict';
  Drupal.behaviors.cbcSettingsSummary = {
    attach: function (context) {
      // The drupalSetSummary method required for this behavior is not available
      // on the common body class administration page, so we need to make sure this
      // behavior is processed only if drupalSetSummary is defined.
      if (typeof jQuery.fn.drupalSetSummary == 'undefined') {
        return;
      }
      $('fieldset#edit-path', context).drupalSetSummary(function (context) {
        if (!$('textarea[name="pages"]', context).val()) {
          return Drupal.t('Not restricted');
        }
        else {
          return Drupal.t('Restricted to certain pages');
        }
      });
      $('fieldset#edit-role', context).drupalSetSummary(function (context) {
        var vals = [];
        $('input[type="checkbox"]:checked', context).each(function () {
          vals.push($.trim($(this).next('label').html()));
        });
        if (!vals.length) {
          vals.push(Drupal.t('Not restricted'));
        }
        return vals.join(', ');
      });

    }
  };
})(jQuery);


