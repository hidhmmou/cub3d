#!/bin/bash
echo "Enter commit message: "
read commit_message

# Ask for confirmation before proceeding
echo "Are you sure you want to push your changes to GitHub? (y/n) "
read confirm

if [ "$confirm" == "y" ]; then
    git add .
    git commit -m "$commit_message"
    git push
    echo "Changes pushed to GitHub."
else
    echo "Push cancelled."
fi
