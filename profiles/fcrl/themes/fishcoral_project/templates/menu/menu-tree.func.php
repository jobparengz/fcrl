<?php

/**
 * @file
 * menu-tree.func.php
 */

/**
 * Fishcoral Project theme wrapper function for the primary menu links.
 */
function fishcoral_project_menu_tree__primary(&$variables) {
  return '<ul class="menu nav navbar-nav">' . $variables['tree'] . '</ul>';
  // Code after RETURN statement cannot be executed.
  // Add views exposed search.
  // $block = block_load('fcrl_sitewide', 'fcrl_sitewide_search_bar');
  // if ($block) :
  //   $search = _block_get_renderable_array(_block_render_blocks(array($block)));
  //   print render($search);
  // endif;
  // End views exposed search.
}
