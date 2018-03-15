# This script helps us copy all of the library files we need from
# other repositories and keep track of what versions were copied.

library()
{
  LIBDIR=$1
  KEYWORDS=$LIBDIR/keywords.txt
  COMPONENT_VERSIONS=$LIBDIR/components.txt

  echo -n > $COMPONENT_VERSIONS
  (cat $LIBDIR/local_keywords.txt; echo) > $KEYWORDS
}

copylib()
{
  local origin=$1
  shift

  local dir=$1
  shift

  (cd $dir && git diff --quiet) || {
    echo "error: uncommitted changes in $dir"
    return
  }

  echo Copying from $dir

  # Copy the code files.
  until [ -z "$1" ]
  do
    cp $dir/$1 $LIBDIR
    shift
  done

  # Copy the keywords.
  (cat $dir/keywords.txt; echo) >> $KEYWORDS

  # Add an entry to components.txt.
  local ver=`cd $dir && git describe --tags`
  echo $origin $ver >> $COMPONENT_VERSIONS
}

library .

copylib https://github.com/pololu/lsm303-arduino ../LSM303/ LSM303{.cpp,.h}
copylib https://github.com/pololu/l3g-arduino ../L3G/ L3G{.cpp,.h}
copylib https://github.com/pololu/pololu-buzzer-arduino ../pololu-buzzer-arduino/PololuBuzzer PololuBuzzer{.cpp,.h}
copylib https://github.com/pololu/pushbutton-arduino ../pushbutton-arduino/ Pushbutton{.cpp,.h}
copylib https://github.com/pololu/qtr-sensors-arduino ../qtr-sensors-arduino/ QTRSensors{.cpp,.h}
