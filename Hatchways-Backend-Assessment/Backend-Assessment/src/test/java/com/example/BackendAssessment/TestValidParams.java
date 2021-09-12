package com.example.BackendAssessment;

import org.json.JSONObject;
import org.junit.jupiter.api.Test;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.autoconfigure.web.servlet.AutoConfigureMockMvc;
import org.springframework.boot.test.context.SpringBootTest;
import org.springframework.test.web.servlet.*;

import okhttp3.Call;
import okhttp3.OkHttpClient;
import okhttp3.Request;
import okhttp3.Response;

import static org.springframework.test.web.servlet.request.MockMvcRequestBuilders.get;
import static org.springframework.test.web.servlet.result.MockMvcResultHandlers.print;
import static org.springframework.test.web.servlet.result.MockMvcResultMatchers.status;
import static org.springframework.test.web.servlet.result.MockMvcResultMatchers.content;

@SpringBootTest
@AutoConfigureMockMvc
public class TestValidParams {
	
	@Autowired
	private MockMvc mock;
	
	
	@Test
	public void TestingInvalidDirect () throws Exception {
		
		Request request = new Request.Builder().url("https://api.hatchways.io/assessment/solution/"
		 		+ "posts?tags=history,tech&sortBy=likes&direction=desc").method("GET", null).build();
		 
		 OkHttpClient client = new OkHttpClient();
		 Call call = client.newCall(request);
		 Response responseFromApi=null;
		
    	 responseFromApi = call.execute();
    	 JSONObject resJson = new JSONObject(responseFromApi.body().string());
		
		this.mock.perform(get("/api/posts?tags=history,tech&sortBy=likes&direction=desc")).andDo(print())
		.andExpect(status().isOk()).andExpect(content().json(resJson.toString()));
	}

}
