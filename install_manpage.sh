#!/bin/bash

# install_manpage.sh
# Script to install the custom Simple Shell man page

MANPAGE_NAME="shell.1"
DEST_DIR="/usr/local/share/man/man1"

echo "Installing the man page..."

# Check if the man page exists
if [ ! -f "$MANPAGE_NAME" ]; then
  echo "Error: $MANPAGE_NAME not found in the current directory."
  exit 1
fi

# Copy the man page (may require sudo)
echo "Copying $MANPAGE_NAME to $DEST_DIR..."
sudo cp "$MANPAGE_NAME" "$DEST_DIR/"

# Update the man database
echo "Updating man database..."
sudo mandb

echo "Installation complete!"
echo "You can now access the manual with: man shell"
