#!/bin/bash

for i in {1..4}; do
    if [ "$1" == "--input_folder" ] 
        then input_folder=$2;
    elif [ "$1" == "--extension" ]
        then extension=$2;
    elif [ "$1" == "--backup_folder" ]
        then backup_folder=$2;
    elif [ "$1" == "--backup_archive_name" ]
        then backup_archive_name=$2;
    fi
    shift; shift;
done
backup_archive_name=$(basename ${backup_archive_name} .gz);
if ! [ -d ${backup_folder} ] 
    then mkdir ${backup_folder};
else echo "exist"
fi
count=0;
for new_file in $(find ${input_folder} -type f -name "*.${extension}"); do
    copy_file=$(basename ${new_file});
    copy_file=$(basename ${copy_file} .${extension});
    cp "${new_file}" "${backup_folder}/${copy_file}(${count}).${extension}";
    count=$(( ${count} + 1 ));
done
tar -cf ${backup_archive_name} ${backup_folder};
gzip ${backup_archive_name};
echo "done"
