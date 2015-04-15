<?php

/**
 * @file
 * Contains the user view row style plugin.
 */

/**
 * Plugin which performs a user_view on the resulting object.
 *
 * @ingroup views_row_plugins
 */
class viewpane_expose_imagestyle_plugin_row_user_view extends views_plugin_row_user_view {
  /**
   * Override views_plugin_row_user_view to add image styles from pane configuration.
   */
  function render($row) {
    $account = $this->users[$row->{$this->field_alias}];
    $account->view = $this->view;
    $build = user_view($account, $this->options['view_mode']);

    if (!empty($this->display->handler->options['pane_conf'])) {
      $conf = $this->display->handler->options['pane_conf'];
      if (!empty($conf['imagestyle'])) {
        $path = '';
        if (isset($account->picture->uri)) {
          $path = $account->picture->uri;
        }
        // Check for default profile image.
        else {
          // In order to have default profile image ready to be styled with image styles,
          // we need to remove part with file folder path.
          $default_path = variable_get('user_picture_default', '');
          $files_path = variable_get('file_public_path', '');
          $default_path = trim(str_replace($files_path, '', $default_path));
          if ($default_path != '') $path = file_build_uri($default_path);
        }
        if ($path != '' && !empty($conf['imagestyle']['user_picture'])) {
          $build_item = array();
          $build_item['user_picture'] = theme('image_style',
            array(
              'style_name' => $conf['imagestyle']['user_picture'],
              'path' => $path,
            )
          );
          $build['user_picture']['#markup'] = '<div class="user-picture">' . l($build_item['user_picture'], 'user/' . $account->uid, array('html' => TRUE)) . '</div>';
        }
      }
    }

    return render($build);
  }
}
