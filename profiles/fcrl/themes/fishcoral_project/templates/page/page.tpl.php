<?php

/**
 * @file
 * Default theme implementation to display a single Drupal page.
 *
 * @see template_preprocess()
 * @see template_preprocess_page()
 * @see template_process()
 * @see html.tpl.php
 */
?>
<header id="header" class="header">
  <div class="branding container">
    <?php if ($logo): ?>
      <a class="logo navbar-btn pull-left" href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>">
        <img src="<?php print $logo; ?>" alt="<?php print t('Home'); ?>" />
      </a>
    <?php endif; ?>
    <?php if ($site_name || $site_slogan): ?>
      <div class="site-name-wrapper">
        <?php if ($site_name): ?>
          <a class="site-name" href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>">
            <?php print $site_name; ?>
          </a>
        <?php endif; ?>
        <?php if (!empty($site_slogan)): ?>
          <div class="site-slogan"><?php print $site_slogan; ?></div>
        <?php endif; ?>
      </div>
    <?php endif; ?>
    <!-- views exposed search -->
<!--    <?php
      $block = block_load('fcrl_sitewide', 'fcrl_sitewide_search_bar');
      if($block):
        $search = _block_get_renderable_array(_block_render_blocks(array($block)));
        print render($search);
      endif;
    ?> -->
  </div>
  <div class="navigation-wrapper">
    <div class="container">
      <nav class="navbar navbar-default" role="navigation">
        <div class="navbar-header">
          <button type="button" class="navbar-toggle" data-toggle="collapse" data-target="#navbar-collapse">
            <span class="sr-only"><?php print t('Toggle navigation'); ?></span>
            <span class="icon-bar"></span>
            <span class="icon-bar"></span>
            <span class="icon-bar"></span>
          </button>
        </div> <!-- /.navbar-header -->

        <!-- Collect the nav links, forms, and other content for toggling -->
        <div class="collapse navbar-collapse" id="navbar-collapse">
          <?php if ($main_menu): ?>
            <ul id="main-menu" class="menu nav navbar-nav">
              <?php print render($main_menu); ?>
            </ul>
          <?php endif; ?>

          <!-- user menu -->
          <?php
            if($display_login_menu):
              $block = block_load('fcrl_sitewide', 'fcrl_sitewide_user_menu');
              if($block):
                $user_menu = _block_get_renderable_array(_block_render_blocks(array($block)));
                print render($user_menu);
              endif;
            endif;
          ?>
        </div><!-- /.navbar-collapse -->
      </nav><!-- /.navbar -->
    </div><!-- /.container -->
  </div> <!-- /.navigation -->
</header>

<div id="main-wrapper">
  <div id="main" class="main container">

    <?php
    if (!empty($breadcrumb)) :
      print $breadcrumb;
    endif;
    ?>
    <?php print $messages; ?>
    <?php if (!empty($page['help'])): ?>
      <?php print render($page['help']); ?>
    <?php endif; ?>


    <div class="main-row">

      <section>
        <a id="main-content"></a>
        <?php print render($title_prefix); ?>
        <?php if (!empty($title) && empty($is_panel)): ?>
          <h1 class="page-header"><?php print $title; ?></h1>
        <?php endif; ?>
        <?php print render($title_suffix); ?>
        <?php if (!empty($tabs)): ?>
          <?php print render($tabs); ?>
        <?php endif; ?>
        <?php if (!empty($action_links)): ?>
          <ul class="action-links"><?php print render($action_links); ?></ul>
        <?php endif; ?>
        <?php print render($page['content']); ?>
      </section>

    </div>

  </div> <!-- /#main -->
</div> <!-- /#main-wrapper -->

<footer class="footer-distributed">
<div class="container-fluid">
      <div class="footer-left">
      <a href="http://bfar.da.gov.ph">
        <div class="pull-left">
          <img src="http://dev-fishcoral.pantheonsite.io/sites/dashboard/files/bfarlogo.png">
        </div>
      </a>
      <a href="http://asia.ifad.org">
        <div class="pull-left">
          <img src="http://dev-fishcoral.pantheonsite.io/sites/dashboard/files/ifadlogo.png">
        </div>
      </a>
      </div>
      
      <div class="footer-center">

        <div>
          <i class="fa fa-map-marker"></i><p><span>PMO, Basement, PCA BLDG., Elliptical Road, Diliman</span> Quezon City, 1100</p>
        </div>

        <div>
          <i class="fa fa-phone"></i>
          <p>+63 441 1446</p>
        </div>

        <div>
          <i class="fa fa-envelope"></i>
          <p><a href="mailto:fishcoral1421@gmail.com">E-mail Us</a></p>
        </div>

        <?php if ($copyright): ?>
        <small class="copyright pull-right"><?php print $copyright; ?></small>
        <?php endif; ?>
      </div>

      <div class="footer-right">

        <p class="footer-company-about">
          <span>Follow Us</span>
        </p>

        <div class="footer-icons">

          <a href="http://www.facebook.com/FishCORAL.BFAR/"><i class="fa fa-facebook"></i></a>

        </div>

     </div>
</div>
</footer>
