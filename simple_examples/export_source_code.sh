#!/bin/bash

OUTPUT_DIR="pdf_output"
MERGED_PDF="All_Source_Code.pdf"

mkdir -p "$OUTPUT_DIR"

# File extensions to include
EXTENSIONS=("*.cpp" "*.hpp" "*.c" "*.h" "*.py" "*.java" "*.txt")

# Get the top-level folder name containing this script
TOP_FOLDER=$(basename "$(pwd)")

echo "Exporting source code → PDF with folder & filename header..."

for ext in "${EXTENSIONS[@]}"; do
    for file in $ext; do
        if [[ -f "$file" ]]; then
            base=$(basename "$file")
            psfile="$OUTPUT_DIR/${base}.ps"
            pdffile="$OUTPUT_DIR/${base}.pdf"

            echo "Converting: $file → $pdffile"

            # macOS compatible enscript with folder + file header
            enscript -q -2r \
                --header="*** [$TOP_FOLDER] $base ***" \
                -p "$psfile" "$file"

            # Convert PS to PDF
            ps2pdf "$psfile" "$pdffile"

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
