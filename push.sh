#!/bin/bash
echo "Enter commit message: "
read commit_message

# Ask for confirmation before proceeding
echo "Are you sure you want to push your changes to GitHub? (y/n) "
read confirm

if [ "$confirm" == "y" ]; then
    # Add and commit the changes
    git add .
    git commit -m "$commit_message"
    
    # Push the changes to the repository
    git push https://github.com/hidhmmou/cub3d.git origin master
    
    echo "Changes pushed to GitHub."
else
    echo "Push cancelled."
fi
