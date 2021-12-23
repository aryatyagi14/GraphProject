
## Final Project Proposal ##
By: Arya Tyagi, Rahul Kalle, Anami Patel, Chahna Saraiya

**Leading Question**

**Q:** How can we categorize the trust levels of Epinions.com users’ in a signed network graph?

  * How can we display the level of trust between two users?

  * How can we utilize the directed edges of a signed network graph to determine the trustworthiness of a community?

**Dataset Acquisition and Processing**

*Dataset:* https://snap.stanford.edu/data/soc-sign-epinions.html

*Description:* This dataset reveals the trust relationships between users of the consumer review website, Epinions.com. This ‘Web of Trust’ is combined with review ratings to determine whether a review is shown to a user. The Epinions dataset is a directed graph of a signed social network. As such, there is potential for missing data entries for removed/reported reviews, users that delete their accounts, etc. To handle these possible errors, we would tailor our graph constructor implementation to ignore stray edges or otherwise inconsistent data.

*Downloading and Storing the Data:* The dataset can be downloaded from the Stanford SNAP website in the form of a .gz zipped text file. As suggested by the Bureau of Labor Statistics, we will use WinZip to unzip the .gz file. We would store the compressed version in our git repository.

*Data Processing:* The graph constructor implementation would create a node for each individual user account listed in the dataset. A directed edge would connect user A to user B if user A trusts user B. To further process the data, the degree of each node would be determined by an incidentEdges() implementation that only counts directed edges going toward the node. Furthermore, we could process this data using several graph algorithms specifically designed for directed graphs (e.g. Strongly Connected Components) or graphs in general (e.g. Graph Coloring).

**Graph Algorithms**

Traversal:
 * Depth First Search: Implementation would require the set of all nodes and the set of all directed edges. Overall, a similar approach as mp_traversals DFS with a stack to store visited nodes and an iterator to traverse them.

Complex/Uncovered Algorithms:
 * Graph Labeling / Graphic Output of Graph:
     * Node Coloring: For each node in the signed social network graph, a color (graph label) will be assigned based on the sum of the positive and negative directed incident edges pointing to the node. The output color would be based on a gradient (red to green, orange to blue, etc.). This would signify the trustworthiness of each user by summing the signed edges.
     * Node Sizing: Size of node corresponds to the number of directed edges pointing to the node, regardless of sign.

 * Strongly Connected Component:
     * Inspiration: Tarjan’s Strongly Connected Component Algorithm O(m+n)
     * Since the Epinions graph is directed, the strongly connected component algorithm would be relevant to determine trust networks (cliques) within the entire consumer review website. The inputs would be the nodes and their adjacent neighbors, along with the edges. The outputs would be the strongest trust network.


**Timeline**

Task  | Timeline
------------- | -------------
Report | ongoing (weekly)
Dataset Acquisition  | 11/8
Data Processing  | 11/8 to 11/19
Depth First Search | 11/15 to 11/19
Mid-Project Check-in | 11/29 to 12/1
Graph Labeling / Display | 11/29 to 12/3
Strongest Connected Component | 12/6 to 12/10
Final Presentation | 12/6 to 12/13

