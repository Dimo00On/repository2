#!/bin/bash

for i in {1..4}; do
    case "$1" in
        "--input_folder")
            input_folder=$2
        ;;
        "--extension")
            extension=$2
        ;;
        "--backup_folder")
            backup_folder=$2
        ;;
        "--backup_archive_name")
            backup_archive_name=$2
        ;;
    esac
    shift 2;
done
backup_archive_name=$(basename ${backup_archive_name} .gz);
if ! [ -d ${backup_folder} ]
    then mkdir ${backup_folder};
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


