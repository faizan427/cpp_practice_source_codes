#!/bin/bash

OUTPUT_DIR="pdf_output"
MERGED_PDF="All_Source_Code.pdf"

# Create output directory
mkdir -p "$OUTPUT_DIR"

# File extensions to include
EXTENSIONS=("*.cpp" "*.hpp" "*.c" "*.h" "*.py" "*.java" "*.txt")

# Get the top-level folder name containing this script
TOP_FOLDER=$(basename "$(pwd)")

echo "Exporting source code → PDF with folder & filename header..."

# Iterate through each extension and each file
for ext in "${EXTENSIONS[@]}"; do
    for file in $(find . -type f -name "$ext"); do
        if [[ -f "$file" ]]; then
            base=$(basename "$file")
            psfile="$OUTPUT_DIR/${base}.ps"
            pdffile="$OUTPUT_DIR/${base}.pdf"

            echo "Converting: $file → $pdffile"

            # Create PostScript (.ps) file with bold font and font size 11.6
            enscript -q \
                --header="*** [$TOP_FOLDER] $base ***" \
                -f "Courier-Bold12" \
                -p "$psfile" "$file"

            # Check if .ps file was created
            if [[ -f "$psfile" ]]; then
                echo "PostScript file created: $psfile"
            else
                echo "Error: Failed to create PostScript file for $file"
                continue
            fi

            # Convert PostScript (.ps) to PDF
            ps2pdf "$psfile" "$pdffile"

            # Check if the PDF was created
            if [[ -f "$pdffile" ]]; then
                echo "PDF created: $pdffile"
            else
                echo "Error: Failed to create PDF from $psfile"
            fi

            # Remove intermediate PS file
            rm "$psfile"
        fi
    done
done

# Merge PDFs
if compgen -G "$OUTPUT_DIR/*.pdf" > /dev/null; then
    echo "Merging PDFs into $MERGED_PDF..."
    pdfunite "$OUTPUT_DIR"/*.pdf "$MERGED_PDF"
    echo "✔ Done! Output created: $MERGED_PDF"
else
    echo "No PDFs found to merge."
fi
