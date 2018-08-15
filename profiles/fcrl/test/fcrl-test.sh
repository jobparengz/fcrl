#!/bin/bash

# Install dependencies
composer install

# Create Database
mysql -e 'drop database fcrl_test; create database fcrl_test;'

# Install FCRL
cd ..
drush make --prepare-install build-fcrl.make --yes test/drupal
cd test/drupal
drush si fcrl --sites-subdir=default --db-url=mysql://root:@127.0.0.1/fcrl_test --account-name=admin --account-pass=admin  --site-name="FCRL" install_configure_form.update_status_module='array(FALSE,FALSE)' --yes
drush cc all --yes

# Run test server
drush --root=$PWD runserver 8888 &
sleep 4
cd ../

# Run selenium
wget http://selenium.googlecode.com/files/selenium-server-standalone-2.39.0.jar
java -jar selenium-server-standalone-2.39.0.jar -p 4444 &
sleep 5

bin/behat
