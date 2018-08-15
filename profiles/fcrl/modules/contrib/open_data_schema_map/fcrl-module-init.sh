
# Name of the current module.
FCRL_MODULE=`ls *.info | cut -d'.' -f1`

# FCRL branch or tag to use.
FCRL_VERSION="7.x-1.x"

COMPOSER_PATH="$HOME/.config/composer/vendor/bin"

if [[ "$PATH" != *"$COMPOSER_PATH"* ]]; then
  echo "> Composer PATH is not set. Adding temporarily.. (you should add to your .bashrc)"
  echo "PATH (prior) = $PATH"
  export PATH="$PATH:$COMPOSER_PATH"
fi

# Try to grab archived fcrl to speed up bootstrap.
URL="https://s3-us-west-2.amazonaws.com/mis-data-fcrl-archives/fcrl-$FCRL_VERSION.tar.gz"
if wget -q "$URL"; then
  mv fcrl-$FCRL_VERSION.tar.gz ../
  cd ..
  tar -xzf fcrl-$FCRL_VERSION.tar.gz
  # We need to fix the archive process to delete this file.
  chmod 777 fcrl/docroot/sites/default
  rm -rf fcrl/docroot/sites/default/settings.php
  mv $FCRL_MODULE fcrl/
  mv fcrl $FCRL_MODULE
  cd $FCRL_MODULE
  set -e
  cd fcrl
  bash fcrl-init.sh fcrl --skip-init --deps
  cd ..
  echo -ne 'y\n' | ahoy fcrl drupal-rebuild $DATABASE_URL
  ahoy fcrl remake
  echo -ne 'N\n' | ahoy fcrl reinstall
else
  wget -O /tmp/fcrl-init.sh https://raw.githubusercontent.com/MiS/fcrl/$FCRL_VERSION/fcrl-init.sh
  # Make sure the download was at least successful.
  if [ $? -ne 0 ] ; then
    echo ""
    echo "[Error] Failed to download the fcrl-init.sh script from github fcrl. Branch: $FCRL_BRANCH . Perhaps someone deleted the branch?"
    echo ""
    exit 1
  fi
  # Only stop on errors starting now.
  set -e
  # OK, run the script.
  bash /tmp/fcrl-init.sh $FCRL_MODULE $@ --skip-reinstall --branch=$FCRL_VERSION
fi

echo "Linking/Building Module..."
ahoy fcrl module-link $FCRL_MODULE
ahoy fcrl module-make $FCRL_MODULE

# Use the backup if available.
if [ -f backups/last_install.sql ];then
  ahoy drush sql-drop -y &&
  ahoy fcrl sqlc < backups/last_install.sql && \
  echo "Installed fcrl from backup"
else
  ahoy fcrl reinstall
fi

ahoy drush en $FCRL_MODULE -y
ahoy drush updb -y

 #Fix for behat bug not recognizing symlinked feature files or files outside it's root. See https://jira.govdelivery.com/browse/CIVIC-1005
#cp fcrl_workflow/test/features/fcrl_workflow.feature fcrl/test/features/.
