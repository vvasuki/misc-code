USAGE_FILE='/tmp/loadChecker.txt';
rm $USAGE_FILE 2>/dev/null;

function checkMachines()
{
    machineType=$1
    maxMachineNumber=$2
    USAGE_FILE=$3
    echo "Checking $machineType machines"| tee -a $USAGE_FILE
    for machineNumber in `seq $maxMachineNumber`
    do
        if [ "$machineType-$machineNumber" == "lhug-8" ]
        then
            continue
        fi
        echo $machineType-$machineNumber | tee -a $USAGE_FILE
        ssh $machineType-$machineNumber "top -b -n 1 |head -n 10">>$USAGE_FILE
    done
}
checkMachines 'lhug' 13 $USAGE_FILE
checkMachines 'uvanimor' 9 $USAGE_FILE
ssh oliphaunt-0 "top -b -n 1 |head -n 10 >>$USAGE_FILE"

echo "See: $USAGE_FILE"
freeFiles=`cat $USAGE_FILE|grep "3 root" -B 10`
if [ ${#freeFiles} -lt 3 ]
then
    echo 'No machine free!'
    cat $USAGE_FILE
else
    echo $freeFiles
fi
