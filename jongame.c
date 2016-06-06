   	int getCampuses (Game g, int player) {
   	    int campuses = g->gameUnis[player].numCampuses;
   	    return campuses;
   	}

   	int getIPs (Game g, int player) {
   	    int IPs = g->gameUnis[player].numIPs;
   	    return IPs;
   	}

   	int getPublications (Game g, int player) {
   	    int publications = g->gameUnis[player].numPubs;
   	    return publications;
   	}

   	int getStudents (Game g, int player, int discipline) {
   	    int studentCount = g->gameUnis[player].numStudents[discipline];
   	    return studentCount;
   	}

   	int getExchangeRate (Game g, int player, int disciplineFrom, int disciplineTo) {
   	    int exchangeRate = 3;

   	    if (disciplineFrom == 0) {
   	        exchangeRate = 0;
   	    } else if (g->gameUnis[player].convCentre[disciplineTo] == TRUE) {
   	        exchangeRate = 2;
   	    } else {
   	        exchangeRate = 3;
   	    }

   	    return exchangeRate;
   	}
