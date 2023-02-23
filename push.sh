#!/bin/bash

# Set up the repository information
username="your_username"
repository="your_repository"
branch="main"

# Get the commit message from the user
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
    git push https://github.com/$username/$repository.git $branch
    
    echo "Changes pushed to GitHub."
else
    echo "Push cancelled."
fi
