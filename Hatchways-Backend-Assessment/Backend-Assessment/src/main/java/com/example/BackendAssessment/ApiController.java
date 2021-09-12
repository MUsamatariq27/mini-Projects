package com.example.BackendAssessment;


import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Set;

import javax.servlet.http.HttpServletResponse;

import org.json.JSONArray;
import org.json.JSONObject;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.RestController;

import okhttp3.OkHttpClient;

import okhttp3.Call;
import okhttp3.Request;
import okhttp3.Response;



@RestController
@RequestMapping("/api")
public class ApiController {
	
	@GetMapping(path = "/ping")
	public Map<String, Boolean> ping() {
		
		Map<String, Boolean> map = new HashMap<>();
		
		map.put("sucess", true);
		return map;
		
	}
	
	@RequestMapping(value = "/posts{tags}{sortBy}{direction}", method = RequestMethod.GET)
	public void getPosts(@RequestParam (value = "tags", required=false) String tags,
			@RequestParam(value = "sortBy", defaultValue = "id") String sortBy,
			@RequestParam(value = "direction", defaultValue = "asc") String direction,
			HttpServletResponse response) throws IOException {
		
		JSONObject obj=new JSONObject();
		
		PrintWriter out = response.getWriter();
        response.setContentType("application/json");
        response.setCharacterEncoding("UTF-8");
		
		
		if (tags == null || tags.isBlank() ) {
			obj.put("error", "Tags parameter is required and can't be blank");
	        response.setStatus(HttpServletResponse.SC_BAD_REQUEST);
	        out.print(obj);
	        out.flush(); 
			
		}
		
		else if ( !direction.equals("asc") && !direction.equals("desc") ) {
			
			obj.put("error", "direction parameter is invalid");
	        response.setStatus(HttpServletResponse.SC_BAD_REQUEST);
	        out.print(obj);
	        out.flush(); 
		}
		else if ( !sortBy.equals("id") && !sortBy.equals("popularity") && !sortBy.equals("reads") && !sortBy.equals("likes") ) {
			
			obj.put("error", "sortBy parameter is invalid");
	        response.setStatus(HttpServletResponse.SC_BAD_REQUEST);
	        out.print(obj);
	        out.flush();
		}
		
		
		else {
	
			List<JSONObject> postList = new ArrayList<JSONObject>();
			Set<Integer> set = new HashSet<>();
			
			String[] tagsArr = tags.split(","); 
			
			for (int i=0; i < tagsArr.length; i++) {
				
				if (!tagsArr[i].isBlank()) {
					
					 Request request = new Request.Builder().url("https://api.hatchways.io/assessment/blog/posts?tag=" 
		                        + tagsArr[i]).method("GET", null).build();
					 
					 OkHttpClient client = new OkHttpClient();
					 Call call = client.newCall(request);
	                 Response responseFromApi=null;
	                 
	                 
	                 try {
	                	 responseFromApi = call.execute();
	
	                	 JSONObject resJson = new JSONObject(responseFromApi.body().string());
	                	 JSONArray jArr =  resJson.getJSONArray("posts");
	                	 
	                	for (Object each: jArr) {
	                		
	                		 JSONObject o = (JSONObject)each;
	                		
	                		 if (!set.contains(o.getInt("id")) ){
	                			 postList.add(o);
	                			 set.add(o.getInt("id")); 
	                		 }
	                	}
	                	Collections.sort(postList, new SortBasedOnsortByDir(sortBy, direction));
	                	 
	                 }
	                 catch(Exception e) {
	                	 break;
	                 }
				}
			}
			
			obj.put("posts", postList);
	        response.setStatus(HttpServletResponse.SC_OK);
	        out.print(obj);
	        out.flush();
		}
		
	}

}
