echo "*** DEPRECATED ***"
echo "*** DEPRECATED ***"
echo "*** DEPRECATED ***"
echo "*** DEPRECATED ***"
echo "Use .scripts/fcrl-test.sh"

cd $1
shift
echo $*
bin/behat $*
