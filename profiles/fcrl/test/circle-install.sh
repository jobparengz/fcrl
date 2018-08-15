#!/bin/bash
# Make sure an error during execution gets passed along to circleCI
set -e
#if [ -f ~/backups/fcrl-install.sql ]; then
# DON'T USE THE CACHED BACKUP FOR A WHILE UNTIL THE FCRL REFACTORING IS DONE. --Frank
if false; then
# Use the cached install backup.
    echo "===> Loading install from cached database found at ~/backups/fcrl-install.sql."
    cp circle.settings.php sites/default/settings.php
    drush sql-drop -y && drush sqlc < ~/backups/fcrl-install.sql
else
    # Do full installation
    echo "===> No cached database found at ~/backups/fcrl-install.sql. Installing from scratch."
    echo "drush si fcrl --sites-subdir=default --db-url=$DATABASE_URL --account-name=admin --account-pass=admin  --site-name="FCRL" install_configure_form.update_status_module='array(FALSE,FALSE)' --yes"
    drush si fcrl --sites-subdir=default --db-url=$DATABASE_URL --account-name=admin --account-pass=admin  --site-name="FCRL" install_configure_form.update_status_module='array(FALSE,FALSE)' --yes
    drush cc drush; drush cc all --yes
    #store cached backup
    mkdir -p ~/backups
    drush sql-dump > ~/backups/fcrl-install.sql
fi
