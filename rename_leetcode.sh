#!/bin/bash

# Iterate over all files in the current directory
for old_name in *; do
    # Check if it's a file and not a directory
    if [ -f "$old_name" ]; then
        # Extract the number and the name part
        # Using regex to capture the number and the rest of the name
        if [[ "$old_name" =~ ^([0-9]+)[[:space:]]+(.+)$ ]]; then
            number="${BASH_REMATCH[1]}"
            name_part="${BASH_REMATCH[2]}"

            # Pad the number with leading zeros to 4 digits
            padded_number=$(printf "%04d" "$number")

            # Convert spaces to hyphens and convert to lowercase for the name part
            # Convert to lowercase first
            lowercased_name_part=$(echo "$name_part" | tr '[:upper:]' '[:lower:]')
            # Replace spaces with hyphens
            new_name_part=$(echo "$lowercased_name_part" | sed 's/[[:space:]]\+/-/g')


            # Construct the new file name
            new_name="${padded_number}-${new_name_part}"

            # Only rename if the name has actually changed to avoid unnecessary git operations
            if [ "$old_name" != "$new_name" ]; then
                echo "Renaming '$old_name' to '$new_name'"
                git mv "$old_name" "$new_name"
            else
                echo "Skipping '$old_name' as it's already in the desired format."
            fi
        else
            echo "Skipping '$old_name' - does not match expected format '{Number} Some Name'."
        fi
    fi
done

echo "Renaming process complete. Now, commit and push changes."
echo "git commit -m \"Standardize LeetCode file names\""
echo "git push origin main" # Or your default branch name (e.g., master)
