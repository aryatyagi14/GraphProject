## Project Results <br />
*Rahul Kalle, Arya Tyagi, Anami Patel, and Chahna Saraiya* <br />
#

  When we started this project, the first task we completed was creating the Vertex and Edge classes. In this way, we could start with classes we were more comfortable with and then move on to classes we were less comfortable with, like SCC (Strongly Connected Component). In the Vertex class, we created setters, getters and a setTrustLevel() function. This is specific to our data set in the following way: for each vertex we have a “trust level” given, which is either 1 if the user trusts another user or -1 if they do not. We decided that this value should correspond to the color of the node; therefore, we made the vertex hue range from yellow to pink (with blue as the color for neutral) depending on how many people relatively trusted or distrusted another person. As for Edge, the color of the edge corresponds to ‘trusting’, green, or ‘distrusting’, red.  After completing the Vertex and Edge classes, we decided that the logical next step would be to implement the Graph class, but before we could implement that, we needed a way to go through all of the data in the file. This is why we created the Parsing_Utils class, where we wrote code which went through the file and put the data in a form that we could actually manipulate and use. 

  At this point during our project development, we decided we needed a way to check if our components were working so we started working on a Makefile. Our first attempt left us with a file that looked similar to the ones from past MPs but was not functional. We then decided to outsource and do some research online to see how other people have written their Makefiles. Ultimately, we were unable to find a solution, so we went to office hours to get it running. For the Graph class, we decided it would be very useful to create a vector of both the vertices and edges. In addition to that, we created a class variable for an adjacency list which allowed us to improve runtime as we had learned that this was the best implementation in class. We also wrote the implementation of the Depth First Search (DFS) that would be used to iterate through each of the vertices in the graph in order to display them accurately. The exact output of the DFS can be displayed in the terminal but its functionality is also demonstrated in the image of the graph. Next came the Draw_Utils class which eventually aided in drawing and printing out our finished graph. We thought the best approach would be to copy the CS225 folder utilized in our MPs into our final project folder so that we had access to the PNG and HSLAPixel classes. Our Draw_Utils class drew the vertices (represented by circles) and edges (represented by lines) included in the data set and housed the implementation of the following algorithms: edge coloring, node coloring, and node sizing. The vertices were colored on a range that varied from pink to blue to yellow-green, in the order of distrust to trust. The edges were drawn in either green to signify trust, or red to demonstrate distrust. The size of each vertex corresponded to the degree of that node. In other words, the size of the vertex demonstrated how active that user was on the Epinions website. The vertices and edges symbolizing the trust relationships between users were drawn in a way such that the illustration was intelligible and well spaced out. 

  Lastly, we created the Strongly Connected Component (SCC) class, which finds and prints out which sections of the graph are strongly connected components. To begin this class, we researched which algorithm would best fit our dataset. We ultimately decided to use Tarjan's Strongly Connected Component because we as a group could understand it better than the other algorithms we came across. After writing the implementation, we realized that we had used a recursive algorithm which caused our code to segfault due to how large our dataset is (upwards of 130,000 nodes). We met with our group mentor to get some advice on how to deal with this issue. We also went to office hours for this part of the project to get it working, and fortunately the TA who helped us had done the same algorithm on their project. They were able to give us some helpful advice and a link to a Youtube video which gave us more clarity on why Tarjan's Algorithm was needed and how it functioned. It is important to note that our SCC class did not run on the full dataset because there was a stack overflow due to the sheer amount of data; however, we can prove that our SCC class works as intended because it is functional on a subset of our dataset. Therefore, at the end of our analysis, we had a graph named “Epinons.png” which showed the different components we implemented in our Graph class, such as how we displayed the 841,372 edges and 131,828 vertices. 

  After we created the graph, we were able to analyze it and notice the patterns created as a result of our complex node and edge coloring algorithms. For example, we noticed that there seem to be more green edges than red edges in general, indicating that overall there is more trust than distrust among Epinions users. In general, we also noticed that there were more blue nodes than yellow or pink nodes. Since in our code we had green represent trust and pink represent distrust, blue was a neutral color. In other words, a blue node indicates that a person was not particularly trusted or distrusted or that there were an equal amount of people who trusted or distrusted them. From the graph, it also looked like the least amount of nodes were colored yellow, meaning that overall there were relatively few people who were considered to be trustworthy. Something else we also noticed about the nodes was that very few of them were large, meaning that there were not many Epinions.com users who were significantly active on the site. Lastly, we also noticed that some nodes had no ingoing or outgoing edges, which simply meant that that particular user did not trust anybody else and nobody else trusted that user; therefore, nothing could be determined about these users. 

  It is evident that our proposed algorithms were successfully able to produce the relevant outputs. This is visible both by the Epinions.png generated as well as the assertions passed in the test cases for the code written.