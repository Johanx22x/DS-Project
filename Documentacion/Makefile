FILES = docs/*.md \

OUTPUT = DocumentacionProyecto.pdf

FLAGS = --bibliography=bibliography.bib \
		--from=markdown \
		--to=latex \
		--citeproc \
		--toc \
		--highlight-style=tango \
		--metadata-file=metadata.yaml \
		-s \
		-t pdf

all: pdf

pdf:
	pandoc -o $(OUTPUT) $(FLAGS) $(FILES)

clean:
	rm DocumentacionProyecto.pdf
