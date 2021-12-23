## Development

**Week of 11/08/21** <br />
The team decided to use a dataset about the trustworthiness of fellow customers based their item reviews from Epinions.com. We then formulated our ideas for what algorithms we could use after researching different methods. We decided on algorithms that would do the following: graphic representation in terms of node sizing, changing the color of nodes, the weight of the edges. In addition to that, we decided to use a Depth-First-Search as our traversal algorithm. We generated a rough timeline regarding the smaller subtasks that we would need to complete. The team also talked about when our weekly meetings would be and then how to settle any potential disagreements.


**Week of 11/15/21** <br />
The team allocated tasks to pairs of group members to complete before our next meeting. Chahna and Anami worked on the implementation of the Edge and Vertex classes. Rahul and Arya worked on parsing the data and the function that will be used to read in the data file. The latter pair also attempted to set up the make file for our final project but were unable to make the corresponding code compile. We then reconvened to catch every group member up on the progress made and then set our goals for the coming weeks.


**Week of 11/22/21** <br />
The team allocated the tasks of completing the DFS and Graph functions to pairs of group members to ideally complete before the next meeting. The group discussed what progress had been made and what was remaining so that we were prepared for our halfway checkin with our mentor. The team debugged our parser so that the weights were being read in accurately. The issues with the Make file were resolved so that the project was able to compile.


**Week of 11/29/21** <br />
This week, the team completed the DFS class and functions as well as the Graph class. Rahul and Arya worked on the DFS class and submitted the code to the group mentor so that it could be checked for its accuracy. They worked on this class by seeing how the BFS functions were made in the lectures and ammending them to allow us to get a working DFS traversal. Chahna and Anami worked on the Graph class. All of the team members met during the week to catch all the group members up on the progress that was made by each pair and also to work together to write the code for the Draw_Utils class which creates a PNG which will display the actual graph. On Sunday, the group met to debug the graph class and made sure we were able to actually see the display of vertices and edges.  


**Week of 12/06/21** <br />
This week, the team started to work on the strongly connected component algorithm and tried to discuss ways to better display the graph through clustering the data. After consulting online resources for understanding Tarjan's SCC Algorithm, the team was able to implement and test the algorithm on the Epinions.com dataset. Due to the enormous size of the dataset, and the recursive nature of the algorithm, running the SCC code printed out a large number of strongly connected components before causing a stack overflow error. To resolve the SCC stack overflow issue, the team met with our mentor who suggested that we run SCC on a subset of the Epinions.com data and similarly display only a portion of the graph to ensure that the algorithm functioned properly and was readable. The team then met in pairs to complete the test suite and work on the final presentation, results report, and README file. 

