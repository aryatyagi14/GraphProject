# csarai2-rahulvk2-anamivp2-aryat2

*Final Project for csarai2-rahulvk2-anamivp2-aryat2* 

Video: https://drive.google.com/file/d/12ebUkHP-RxGTEvgHlxYuGnbG0jKGTCt1/view?usp=sharing

**Description**


**Major Code, Data, Results** <br />
The important code we created is located in the src folder. In the src folder you will see the cs225 folder we used and the .h/.cpp files for all the classes we made. The whole dataset, 'soc-sign-epinions.txt', is located at the bottom of our repository. The main.cpp is where we actually use the code we created to store the graph in Epinions.png. The file paths for the input dataset, output png for graphic display, and output text file for SCC can be changed within main.cpp.

**Compiling Project/Building and Running the Executable**  <br />
If using FastX, make sure to run 'module load llvm/6.0.1' to ensure you have the correct libraries in order to run our code. This was nesscessary for some of our teammates to actually compile and run the code. To make the project type 'make project' and to run the project and create the graph type './project'. After running the project you should see that the Epinions.png has been updated and it displays the data accurately. You should also see that the scc.txt has been updated as well with the strongly connected components. Each line in the scc.txt file will have all the vertex ids of every node in that strongly connected component. 

**Compiling Test Suites** <br />
To make test suites type 'make test' and to run the tests type './test' in the terminal.
After running the test suites, you should see the test cases that have passed or failed and relevant details displayed in the terminal.

All of the test cases correspond to their respective classes and are located in the tests folder. The Vertex and Edge test suites test the setters and getters. In order to test the DFS and Parsing_Utils classes, we created two smaller test data sets (named sample_graph.txt and test_dataset.txt) which are also located in the tests folder. For DFS we ensured that every node was visited and that each node had the appropriate data associated with it. In Parsing_Utils, we made sure the data was being read in correctly. For the graph class, we checked the getters, setters, and the trust calculation which affects the color of each node on the graph. For the Strongly Connected Component tests we made sure that the strongest components were identified and put in the output file, 'test-scc.txt'. For the Draw_Utils class, we tested that a graph was drawn correctly based on the sample data that was provided and saved to 'test-graph.png'.




