
if [ "$HOSTNAME" = "cli" ]; then
  HOST=cli
else
  HOST=localhost
fi

cp ./fcrl/.ahoy/.scripts/.ht.router.php ./docroot/
cd ./docroot

echo $HOST
php -S $HOST:8888 .ht.router.php
