/**
 * @file
 * JS for FCRL site.
 */
(function ($) {

  /**
   * Shows and hides a description for Drupal form elements.
   */
  $.fn.fcrlFormsHide = function () {
    this.each(function () {
      $(this).addClass('compact-form-wrapper');
      var desc = $(this).find('.description').addClass('compact-form-description');
      var input = $(this).find('input');
      desc.click(function () {
        input.focus();
      });
      if ($(input).html() == '') {
        var input = $(this).find('textarea');
      }
      if ($(input).html() == null) {
        var input = $(this).find('input');
      }
      input.addClass('compact-form-input')
      input.blur(function () {
        if (input.val() === '') {
          desc.fadeIn('fast');
        }
      });
      input.keyup(function () {
        if (input.val() != '') {
          desc.hide();
        }
      });
      if (input.val() != '') {
        desc.css('display', 'none');
      }
    });
  }

  /**
   * Shows and hides a description for Autocomplete Deluxe form elements.
   */
  $.fn.fcrlFormsAutoDeluxeHide = function () {
    this.each(function () {
      $(this).addClass('compact-form-wrapper');
      var desc = $(this).find('.description').addClass('compact-form-description');
      var input = $(this).find('#autocomplete-deluxe-input');
      desc.click(function () {
        input.focus();
      });
      input.focus(function () {
        desc.hide();
      });
      if ($('#autocomplete-deluxe-item').html() != null) {
        desc.css('display', 'none');
      }
      if ($(this).find('input').val() != '') {
        desc.css('display', 'none');
      }
    });
  }

  Drupal.behaviors.fcrlSite = {
    attach: function (context, settings) {
      // Autohide selected elements.
      var elements = "#views-exposed-form-dataset-page,#block-fcrl-sitewide-fcrl-sitewide-search-bar,#views-exposed-form-groups-search-entity-view-1,#views-exposed-form-user-profile-search-entity-view-1";
      $(elements, context).fcrlFormsHide();
      var autoDeluxeElements = ".field-name-field-tags";
      $(autoDeluxeElements, context).fcrlFormsAutoDeluxeHide();

      // Toggle button for text-format.
      $('.filter-help.form-group p').append(' | ' + '<a href="#" class="text-help-toggle">' + Drupal.t('Toggle text format') + '</a>');
      //$('.form-type-select').hide();
      $('.filter-guidelines-processed').hide();
      $('.text-help-toggle').click(function(e) {
        e.preventDefault();
        $('.form-type-select').toggle();
        $('.filter-guidelines-processed').toggle();
      });
    }
  }

  Drupal.behaviors.fcrl508Site = {
    attach: function (context, settings) {
      $('#edit-operation').attr('aria-label', 'Operation');
      $('input.bef-datepicker').attr('aria-label', 'Date popup');
      $('a.tabledrag-handle').html('<div class="handle">&nbsp;</div><span class="element-hidden">Drag and drop"</span>');
    }
  }

})(jQuery);
