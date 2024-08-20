class Solution {
public:

    int dijkstraShortestDistance(int n, int src, unordered_map<int ,list<pair<int ,int>>>&adj , int&distanceThreshold) {
		vector<int> dist(n+1, INT_MAX);
		set<pair<int,int> > st;

		//INTIAL STATE -> (0,src)
		st.insert({0,src});
		dist[src] = 0;

        int reachable = 0;



		//distance updation logic 
		while(!st.empty()) {
			auto topElement = st.begin();
			pair<int, int> topPair = *topElement;
			int topDist = topPair.first;
			int topNode = topPair.second;
			//remove the topNode
			st.erase(st.begin());

            if(topNode != src && topDist <= distanceThreshold){
                ++reachable;
            }



			//update distance of nbr
			for(pair<int,int> nbrPair: adj[topNode]) {
				int nbrNode = nbrPair.first;
				int nbrDist = nbrPair.second;
				if(topDist + nbrDist < dist[nbrNode]) {
					//found a new shorter distnace
					//now update: 
					
					// -> set ki entry
					//find previousEntry and delete it
					auto previousEntry = st.find({dist[nbrNode], nbrNode});
					if(previousEntry != st.end()) {
						// entry present in set
						st.erase(previousEntry);
					}
					// -> dist ka array
					dist[nbrNode] = topDist + nbrDist;
					//create a new entry in the set for new distance
					st.insert({dist[nbrNode], nbrNode});
				}
			}
		}
        return reachable;
		 
	}


    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        
        unordered_map<int , list<pair<int , int>>>adj;

        for(auto edge:edges){
            int&u = edge[0];
            int&v = edge[1];
            int&w = edge[2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w}); 


        }

        int city = 0;
        int mincities = INT_MAX;
        for(int u = 0 ; u< n ;++u){
            int count = dijkstraShortestDistance(n ,u , adj , distanceThreshold );
            if(count <=  mincities){
                mincities = count;
                city = u;


            }
        }
        return city;

        

        
    }
};