SHELL=/bin/bash

fast:
	mkdir -p run
	cp -r pic logos tex/* thesisclass.cls bib/* run/
	cd run && pdflatex thesis.tex
	cp run/thesis.pdf Thesis.pdf

again:
	test -e run || (mkdir run && tex/* thesisclass.cls bib/* pic logos run/ )
	cd run && pdflatex thesis.tex
	cp run/thesis.pdf Thesis.pdf

full:
	mkdir -p run
	cp -r pic logos tex/* thesisclass.cls bib/* run/
	cd run && pdflatex thesis.tex
	cd run && bibtex thesis
	cd run && pdflatex thesis.tex
	cd run && pdflatex thesis.tex
	cp run/thesis.pdf Thesis.pdf

warn:
	mkdir -p run
	cp -r pic logos tex/* thesisclass.cls bib/* run/
	cd run && pdflatex thesis.tex &> /dev/null
	cd run && bibtex thesis
	cd run && pdflatex thesis.tex &> /dev/null
	cd run && pdflatex thesis.tex | grep -i warn
	cp run/thesis.pdf Thesis.pdf

txt:
	mkdir -p run
	cp -r pic logos tex/* thesisclass.cls bib/* run/
	cd run && detex thesis.tex > thesis.txt
	awk 'NF' run/thesis.txt > thesis.txt #remove empty lines	

clean:
	rm -rf run/*
	rm -rf *.log
	rm -rf tex/*.tex~
	rm -f Makefile~
