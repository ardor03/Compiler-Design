make 
./final ../tests/test1.py
dot -Tpdf tree.dot -o tree1.pdf
rm -r tree.dot
./final ../tests/test2.py
dot -Tpdf tree.dot -o tree2.pdf
rm -r tree.dot
./final ../tests/test3.py
dot -Tpdf tree.dot -o tree3.pdf
rm -r tree.dot
./final ../tests/test4.py
dot -Tpdf tree.dot -o tree4.pdf
rm -r tree.dot
./final ../tests/test5.py
dot -Tpdf tree.dot -o tree5.pdf
rm -r tree.dot