drush si fcrl --root=docroot --verbose --account-pass='admin' "$1" --site-name='FCRL' install_configure_form.update_status_module='array(FALSE,FALSE)' --yes && \
  drush --root=docroot sql-dump > backups/last_install.sql.tmp && \
  mv backups/last_install.sql.tmp backups/last_install.sql && \
  echo "Installed FCRL and created a new backup at backups/last_install.sql"
