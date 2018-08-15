echo "Installing dependencies.."
cd fcrl
bash .ahoy/.scripts/composer-install.sh test

test/bin/phpunit --configuration test/phpunit $@
