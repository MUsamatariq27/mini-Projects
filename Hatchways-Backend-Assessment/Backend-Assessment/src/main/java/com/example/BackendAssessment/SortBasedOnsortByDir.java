package com.example.BackendAssessment;

import java.util.Comparator;

import org.json.JSONException;
import org.json.JSONObject;

public class SortBasedOnsortByDir implements Comparator<JSONObject> {
	
	String sortBy = "";
	String direction = "";
	
	public SortBasedOnsortByDir (String sortby, String dir){
		
		this.sortBy = sortby;
		this.direction = dir;
		
	}
	
	@Override
    public int compare(JSONObject comp1, JSONObject comp2) {
        try {
        	if (this.direction.equals("desc"))
        		return comp1.getInt(sortBy) < comp2.getInt(sortBy) ? 1 : (comp1
                        .getInt(sortBy) > comp2.getInt(sortBy) ? -1 : 0);
        	else
        		return comp1.getInt(sortBy) > comp2.getInt(sortBy) ? 1 : (comp1
                .getInt(sortBy) < comp2.getInt(sortBy) ? -1 : 0);
        } catch (JSONException e) {
            e.printStackTrace();
        }
        return 0;

    }
	
	

}
