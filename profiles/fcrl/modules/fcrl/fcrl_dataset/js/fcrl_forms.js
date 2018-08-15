/**
 * @file
 * JS for FCRL forms.
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
  Drupal.behaviors.fcrlAddtional = {
    attach: function (context, settings) {
      if (settings.fcrlAdditional && context.context) {
        var pos = $('#page').offset();
        $('html, body').animate({ scrollTop: pos.top}, 'fast');
        window.history.pushState("", "", '/node/' +  settings.fcrlAdditional.nid + '/edit?additional=1');
        delete settings.fcrlAdditional;
      }
      $("#edit-addtional").click(function(e) {
        var params = $.deparam.querystring();
        document.location.href='/node/' + params.dataset + '/edit?additional=1';
      });
    }
  }
  Drupal.behaviors.fcrlPush = {
    attach: function (context, settings) {
      if (settings.fcrlPush && context.context) {
        var pos = $('#page').offset();
        $('html, body').animate({ scrollTop: pos.top}, 'fast');
        if (settings.fcrlPush.lang) {
          window.history.pushState("", "", '/' + settings.fcrlPush.lang + '/node/add/resource?dataset=' + settings.fcrlPush.nid);
        }
        else {
          window.history.pushState("", "", '/node/add/resource?dataset=' + settings.fcrlPush.nid);
        }
        // Make sure this doesn't fire again.
        delete settings.fcrlPush;
      }
    }
  }

  Drupal.behaviors.fcrlFieldGroup = {
    attach: function (context, settings) {

      $('fieldset.horizontal-tabs-pane', context).once('fieldgroup-effects', function(i) {
        // Make tab with any value in it focus.
        if ($(this).find('input').val()) {
          $(this).data('horizontalTab').focus();
        }
      });
    }
  }

  Drupal.behaviors.fcrlForms = {
    attach: function (context, settings) {
      //Add aria label to input upload for accesibility
      $('.file-resup-wrapper input').attr('aria-label', 'Upload a file');
      $('.file-widget input').attr('aria-label', 'Upload a file');

      // Causes file to be uploaded automatically.
      $('input.form-file').change(function() {
        $(this).next('input[type="submit"]').mousedown();
      });

      // Autohide selected elements.
      var elements = "#views-exposed-form-dataset-page,#block-fcrl-dataset-fcrl-dataset-search-bar";
      $(elements, context).fcrlFormsHide();
      var autoDeluxeElements = ".field-name-field-tags";
      $(autoDeluxeElements, context).fcrlFormsAutoDeluxeHide();

      // Date module borks if you add a date without a time. This adds a default
      // time if someone picks a date and time has been added yet.
      if ($('#edit-field-temporal-coverage').length) {
        var tempInputDate1 = $('#edit-field-temporal-coverage input:eq(1)');
        var tempInputTime1 = $('#edit-field-temporal-coverage input:eq(2)');
        var tempInputDate2 = $('#edit-field-temporal-coverage input:eq(3)');
        var tempInputTime2 = $('#edit-field-temporal-coverage input:eq(4)');
        $(tempInputDate1).click(function() {
          if ($(tempInputTime1).val() == '') {
            $(tempInputTime1).val('00:00:00');
          }
        });
        $(tempInputDate2).click(function() {
          if ($(tempInputTime2).val() == '') {
            $(tempInputTime2).val('00:00:00');
          }
        });
      }
      $("#node_dataset_form_group_additional .description").each(function() {
        fcrlFormsBeautyTipPrepare(this, 'label');
      });
      $(".field-widget-leaflet-widget-widget .fieldset-description").appendTo($(".field-widget-leaflet-widget-widget fieldset"));
      $(".field-widget-leaflet-widget-widget .fieldset-description").each(function() {
        fcrlFormsBeautyTipPrepare(this, 'legend');
      });
      $(".field-type-datetime.field-name-field-temporal-coverage .fieldset-description").appendTo($(".field-type-datetime.field-name-field-temporal-coverage fieldset"));
      $(".field-type-datetime.field-name-field-temporal-coverage .fieldset-description").each(function() {
        fcrlFormsBeautyTipPrepare(this, 'legend');
      });
    }
  }

  function fcrlFormsBeautyTipPrepare(that, label) {
    var desc = $(that).html();
    var link = $(that).find('a').attr('href');
    if (link) {
      $(that).html('');
      $(that).prevAll(label).append('<a class="bt-pop" target="_blank" href="' + link + '" title="#"><i class="icon-small icon-external-link"></i></a>');
      $(that).prevAll(label).find("a.bt-pop").bt(desc, {
       spikeLength: 20,
       spikeGirth: 20,
       cornerRadius: 5,
       shrinkToFit: true,
       padding: 10,
       width: '400px',
       fill: '#EAEAEA',
       strokeWidth: 1,
       strokeStyle: '#CCC',
       cssStyles: {color: '#666', width: 'auto'}});
    }
  }


})(jQuery);
