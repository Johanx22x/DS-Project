#!/bin/sh

pandoc docs/* -t pdf -s -o DocumentacionProyecto.pdf --metadata-file=meta.yaml --bibliography=references.bib --citeproc --toc --highlight-style=tango

