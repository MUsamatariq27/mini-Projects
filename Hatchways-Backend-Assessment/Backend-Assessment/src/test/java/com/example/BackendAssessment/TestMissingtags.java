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
public class TestMissingtags {
	
	@Autowired
	private MockMvc mock;
	
	//missing tags parameter
	@Test
	public void TestingMissingTags () throws Exception {
		JSONObject obj=new JSONObject();
		obj.put("error", "Tags parameter is required and can't be blank");
	
		this.mock.perform(get("/api/posts?sortBy=likes&direction=desc")).andDo(print()).andExpect(status().isBadRequest())
		.andExpect(content().json(obj.toString()));
	}
	
	@Test
	public void TestingBlankTags () throws Exception {
		JSONObject obj=new JSONObject();
		obj.put("error", "Tags parameter is required and can't be blank");
	
		this.mock.perform(get("/api/posts?sortBy=likes&direction=desc")).andDo(print()).andExpect(status().isBadRequest())
		.andExpect(content().json(obj.toString()));
	}
	
	

}
