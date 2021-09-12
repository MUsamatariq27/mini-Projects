package com.example.BackendAssessment;

import org.json.JSONObject;
import org.junit.jupiter.api.Test;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.autoconfigure.web.servlet.AutoConfigureMockMvc;
import org.springframework.boot.test.context.SpringBootTest;
import org.springframework.test.web.servlet.*;
import static org.springframework.test.web.servlet.request.MockMvcRequestBuilders.get;
import static org.springframework.test.web.servlet.result.MockMvcResultHandlers.print;
import static org.springframework.test.web.servlet.result.MockMvcResultMatchers.status;
import static org.springframework.test.web.servlet.result.MockMvcResultMatchers.content;

@SpringBootTest
@AutoConfigureMockMvc
public class TestInvalidParam {
	
	@Autowired
	private MockMvc mock;
	
	private JSONObject obj=new JSONObject();
	
	//missing tags parameter
	@Test
	public void TestingInvalidSortBy () throws Exception {
		
		obj.put("error", "sortBy parameter is invalid");
	
		this.mock.perform(get("/api/posts?tags=history,tech&sortBy=random&direction=desc")).andDo(print())
		.andExpect(status().isBadRequest()).andExpect(content().json(obj.toString()));
	}
	
	@Test
	public void TestingInvalidDirect () throws Exception {
		
		obj.put("error", "direction parameter is invalid");
	
		this.mock.perform(get("/api/posts?tags=history,tech&sortBy=likes&direction=up")).andDo(print())
		.andExpect(status().isBadRequest()).andExpect(content().json(obj.toString()));
	}

}
