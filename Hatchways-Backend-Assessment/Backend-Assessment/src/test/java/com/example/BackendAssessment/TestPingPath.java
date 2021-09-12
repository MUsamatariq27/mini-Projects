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
public class TestPingPath {
	
	@Autowired
	private MockMvc mock;
	
	@Test
	public void TestingApiPing () throws Exception {
		JSONObject obj=new JSONObject();
		obj.put("sucess", true);
	
		this.mock.perform(get("/api/ping")).andDo(print()).andExpect(status().isOk())
		.andExpect(content().json(obj.toString()));
	}

	


}
