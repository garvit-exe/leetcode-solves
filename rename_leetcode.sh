#!/bin/bash

# Iterate over each directory in the current directory
for folder in *; do
    if [ -d "$folder" ]; then # Check if it's a directory
        # Use a regular expression to extract the number and the rest of the name
        if [[ "$folder" =~ ^([0-9]+)\ (.*)$ ]]; then
            number="${BASH_REMATCH[1]}"
            name_part="${BASH_REMATCH[2]}"

            # Pad the number to 4 digits
            padded_number=$(printf "%04d" "$number")

            # Convert name part to lowercase and replace spaces with hyphens
            formatted_name=$(echo "$name_part" | tr '[:upper:]' '[:lower:]' | sed 's/ /-/g')

            # Construct the new folder name
            new_folder_name="${padded_number}-${formatted_name}"

            # Check if the new name is different from the old one
            if [ "$folder" != "$new_folder_name" ]; then
                echo "Renaming '$folder' to '$new_folder_name'"
                git mv "$folder" "$new_folder_name"
            else
                echo "Skipping '$folder' (already in desired format or no change needed)"
            fi
        else
            echo "Skipping '$folder' (does not match expected format '{Number} Some Name')"
        fi
    fi
done

echo "Folder renaming process complete. Review changes with 'git status'."
echo "To commit and push: 'git commit -m \"Rename folders\"' and 'git push'."
