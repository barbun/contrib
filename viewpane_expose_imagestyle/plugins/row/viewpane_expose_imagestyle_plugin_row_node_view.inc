<?php

/**
 * @file
 * Contains the node view row style plugin.
 */

/**
 * Plugin which performs a node_view on the resulting object.
 *
 * @ingroup views_row_plugins
 */
class viewpane_expose_imagestyle_plugin_row_node_view extends views_plugin_row_node_view {
  /**
   * Override views_plugin_row_node_view to add image styles from pane configuration.
   */
  function render($row) {
    if (isset($this->nodes[$row->{$this->field_alias}])) {
      $node = $this->nodes[$row->{$this->field_alias}];
      $node->view = $this->view;

      $build = node_view($node, $this->options['view_mode']);
      // Get our pane configuration.
      if (!empty($this->display->handler->options['pane_conf'])) {
        $conf = $this->display->handler->options['pane_conf'];
        if (!empty($conf['imagestyle'])) {
          foreach ($conf['imagestyle'] AS $field_name => $style) {
            if (!empty($build[$field_name]['#items'])) {
              foreach ($build[$field_name]['#items'] as $key => $item) {
                if (isset($build[$field_name][$key])) {
                  $build[$field_name][$key]['#image_style'] = $style;
                }
              }
            }    
          }
        }
      }
      
      return drupal_render($build);
    }
  }
}
