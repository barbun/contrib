<?php
/**
 * @file
 * Contains the extended display plugin.
 */

/**
 * Custom display for adding allow setting for imagestyles
 */
class viewpane_expose_imagestyle_views_content_plugin_display_panel_pane extends views_content_plugin_display_panel_pane {
  /**
   * Option definition for imagestyle setting default behavior
   */
  function option_definition() {
    $options = parent::option_definition();
    $options['allow']['contains']['expose_imagestyle'] = array('default' => FALSE);

    return $options;
  }

  /**
   * Provide the default form for setting options.
   */
  function options_form(&$form, &$form_state) {
    // It is very important to call the parent function here:
    parent::options_form($form, $form_state);

    switch ($form_state['section']) {
      // Only add  if section is allow because this is called for all sections for some reason.
      case 'allow':
        // Add allow option to the form.
        $form['allow']['#options']['expose_imagestyle'] = t('Expose imagestyle settings');
        break;
    }
  }
}
