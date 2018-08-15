require "minitest/autorun"
require "./fcrl/.ahoy/.scripts/behat-parse-params.rb"

class TestBehatParseParams < MiniTest::Unit::TestCase

  def test_behat_parse_suite
    # return fcrl for fcrl features
    expected = "fcrl"
    actual = behat_parse_suite "/var/www/fcrl/test/features/my.feature"
    assert_equal expected, actual

    expected = "fcrl"
    actual = behat_parse_suite "fcrl/test/features/my.feature"
    assert_equal expected, actual

    # returns custom for custom features.
    expected = "custom"
    actual = behat_parse_suite "/var/www/config/tests/features/my.feature"
    assert_equal expected, actual

    expected = "custom"
    actual = behat_parse_suite "config/tests/features/my.feature"
    assert_equal expected, actual

    # returns fcrl_starter for fcrl_starter features or by default
    expected = "fcrl_starter"
    actual = behat_parse_suite "/var/www/tests/features/my.feature"
    assert_equal expected, actual

    expected = "fcrl_starter"
    actual = behat_parse_suite "tests/features/my.feature"
    assert_equal expected, actual

    expected = "fcrl_starter"
    actual = behat_parse_suite nil 
    assert_equal expected, actual
  end

end
